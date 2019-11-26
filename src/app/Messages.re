open ReasonUrql;
open PokemonStyles;
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

[@bs.scope "Math"] [@bs.val] external random: unit => float = "random";
[@bs.scope "Math"] [@bs.val] external floor: float => int = "floor";
[@bs.send] external toString: (int, int) => string = "toString";

let getRandomInt = (max: int) => {
  floor(random() *. float_of_int(max));
};

let getRandomHex = () => {
  let encode = random() *. float_of_int(16777215) |> floor;
  let hex = encode->toString(16);
  {j|#$hex|j};
};
// let process = createMessage => {
//   open Belt.Option;

//   let newMessage = createMessage##message->Decode.decode;
//   // ->flatMap(createMessage => createMessage##message)
//   // ->getExn
//   // ->Decode.decode;

//   newMessage;
// };
let flattenPokemon = pokemons =>
  pokemons
  |> Array.map(newMessage =>
       switch (newMessage) {
       | Some(newMessage) => Belt.Option.getWithDefault(newMessage##message, "")
       | None => ""
       }
     );
let request = SubscribeNewMessage.make();
open Belt.Option;
// open Decode;
[@react.component]
let make = () => {
  <SubscriptionWithHandler request handler>
    ...{({response}) =>
      switch (response) {
      | Fetching => <text> "Loading"->React.string </text>
      | Data(d) =>
        let newMessages = d->Belt.Array.keepMap(item => Some(item));
        let mapToSchemaState: Js.t('a) => newMessage = (
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
          }
        );

        let messages = newMessages->Belt.Array.map(Decode.decodeResponse);
        let mess1 = messages[0];
        let mess2 = messages[1];
        // Js.log2("mess1",mess1);
        // Js.log2("mess2",mess2);
        // let mess = messages->Belt.Array.keepMap(messages =>messages.id
        let _ = messages->Belt.Array.keepMap(m => m.newMessage.message);
        // messages->Js.log;
        // <text> "Error"->React.string </text>;
      messages
      |> Array.mapi((index, m) =>
           <div className=Styles.dex>
             <h1 className=Styles.dexTitle> m.newMessage.message->Obj.magic->React.string </h1>
           </div>
         )
      |> React.array;

      | Error(_e) => <text> "Error"->React.string </text>
      | NotFound => <text> "Not Found"->React.string </text>
      }
    }
  </SubscriptionWithHandler>;
};