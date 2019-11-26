open ReasonUrql;
[@bs.val]
external prettyStringify: ('a, Js.Nullable.t(unit), int) => string =
  "JSON.stringify";
let jsonify = data =>
  <div>
    <h4 className="card-title"> {React.string("Raw Response")} </h4>
    <pre> {React.string(prettyStringify(data, Js.Nullable.null, 2))} </pre>
  </div>;
type message = {
  id: string,
  message: string,
};
type newMessage = {newMessage: message};
module SubscribeNewMessage = [%graphql
  {|
  subscription subscribeMessage {
    newMessage{
      id
      message
    }
  }
|}
];

let handler = (prevSubscriptions, subscription) => {
  switch (prevSubscriptions) {
  | Some(subs) => Array.append(subs, [|subscription|])
  | None => [|subscription|]
  };
};

// [@bs.scope "Math"] [@bs.val] external random: unit => float = "random";
// [@bs.scope "Math"] [@bs.val] external floor: float => int = "floor";
// [@bs.send] external toString: (int, int) => string = "toString";

// let getRandomInt = (max: int) => {
//   floor(random() *. float_of_int(max));
// };

// let getRandomHex = () => {
//   let encode = random() *. float_of_int(16777215) |> floor;
//   let hex = encode->toString(16);
//   {j|#$hex|j};
// };
// let process = createMessage => {
//   open Belt.Option;

//   let newMessage = createMessage##message->Decode.decode;
//   // ->flatMap(createMessage => createMessage##message)
//   // ->getExn
//   // ->Decode.decode;

//   newMessage;
// };
module Styles = {
  open Css;
  let container =
    style([
      position(absolute),
      display(grid),
      gridTemplateColumns([rem(15.), `fr(1.)]),
      height(pct(100.)),
      width(pct(100.)),
      fontFamily("Roboto"),
    ]);
  let list =
    style([paddingLeft(rem(0.)), margin(rem(-0.5)), overflow(auto)]);

  let listItem =
    style([
      listStyleType(`none),
      padding3(~top=rem(0.5), ~h=rem(0.), ~bottom=rem(0.5)),
      hover([backgroundColor(hex("F29441"))]),
      cursor(`pointer),
    ]);
  let button =
    style([
      color(hex("ffff")),
      backgroundColor(transparent),
      borderColor(transparent),
      fontSize(rem(1.)),
      cursor(`pointer),
      width(pct(100.)),
      textAlign(`left),
    ]);
  let dexTitle =
    style([fontSize(rem(2.)), margin(zero), padding(rem(0.5))]);
};
// let buildPokemonList =
//   React.useCallback0((pokemonList: list(string)) =>
//     pokemonList
//     |> List.map(pokemon =>
//          <li key=pokemon className=Styles.listItem>
//            <h1 className=Styles.dexTitle>
//              {pokemon->React.string}
//            </h1>
//          </li>
//        )
//   );
let flattenPokemon = pokemons =>
  pokemons
  |> Array.map(newMessage =>
       switch (newMessage) {
       | Some(newMessage) =>
         Belt.Option.getWithDefault(newMessage##message, "")
       | None => ""
       }
     );
let request = SubscribeNewMessage.make();
open Belt.Option;
// open Decode;
let mapToSchemaState: Js.t('a) => newMessage =
  newMessageJs => {
    let id = newMessageJs##newMessage##id;
    let message = newMessageJs##newMessage##message;
    // let newMessage = {id, message};
    let decoded = {
      newMessage: {
        id,
        message,
      },
    };
    decoded;
  };
[@react.component]
let make = () => {
  <SubscriptionWithHandler request handler>
    ...{({response}) =>
      switch (response) {
      | Fetching => <text> "Loading"->React.string </text>
      | Data(data) =>
        let newMessagesRaw = data->Belt.Array.keepMap(item => Some(item));
        let newMessages = data => {
          Array.map(newMessage => newMessage, data);
        };
        let decoded = newMessagesRaw->Belt.Array.map(mapToSchemaState);
        Js.log2("Array.map_decoded", decoded);
        Js.log2("Array.map(newMessage", newMessages(newMessagesRaw));
        let newMessages = data->Belt.Array.keepMap(item => Some(item));
        decoded
        |> Array.mapi((index, m) =>
             <div className=Styles.container>
               <h1 className=Styles.dexTitle> m->jsonify </h1>
             </div>
           )
        |> React.array;
      // let messages = newMessages->Belt.Array.map(Decode.decodeResponse);
      // let mess1 = messages[0];
      // let mess2 = messages[1];
      // // Js.log2("mess1",mess1);
      // // Js.log2("mess2",mess2);
      // // let mess = messages->Belt.Array.keepMap(messages =>messages.id
      // let _ = messages->Belt.Array.map(m => m.newMessage.message);
      // messages->Js.log;
      // // <text> "Error"->React.string </text>;
      // newMessages
      // |> Array.mapi((index, m) =>
      //      <div className=Styles.container>
      //        <h1 className=Styles.dexTitle>
      //          {m.newMessage.message->Obj.magic->React.string}
      //        </h1>
      //      </div>
      //    )
      // |> React.array;
      // <ul className=Styles.list>
      //   {buildPokemonList(messages)->Array.of_list->React.array}
      // </ul>;
      // <text> "Error"->React.string </text>;
      | Error(_e) => <text> "Error"->React.string </text>
      | NotFound => <text> "Not Found"->React.string </text>
      }
    }
  </SubscriptionWithHandler>;
};