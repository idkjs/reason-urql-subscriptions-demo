open ReasonUrql;

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
  let dex =
    style([
      display(flexBox),
      flexDirection(column),
      width(pct(100.)),
      borderRadius(pct(5.)),
      background(
        linearGradient(
          deg(45.),
          [(zero, hex("F29441")), (pct(100.), hex("A04AD9"))],
        ),
      ),
      border(px(2), solid, hsl(deg(210.), 23., 95.)),
      overflow(hidden),
      alignItems(center),
       boxShadow(Shadow.box(~x=px(0),~y=px(0), ~blur=px(6), hsl(deg(0.), 0., 80.))),
    ]);
  let dexContainer =
    style([
      display(flexBox),
      alignItems(flexStart),
      justifyContent(center),
      margin(auto),
      width(rem(25.)),
    ]);
};

let request = SubscribeNewMessage.make();

/* Pull out message from response. Annotate function as Js.t('a) => string so that react.element can render or else throws error saying type is message. */
let mapToMessage: Js.t('a) => string =
  newMessageJs => {
    let message = newMessageJs##newMessage##message;
    message;
  };
[@react.component]
let make = () => {
  <SubscriptionWithHandler request handler>
    ...{({response}) =>
      switch (response) {
      | Fetching => <text> "Loading"->React.string </text>
      | Data(data) =>
        /* use keepMap because the response is opition array so we iterate of the array and keep it if it exists/or keep each Some values. Then we map over the array to pull ou the messages we want to display */
        let messages =
          data
          ->Belt.Array.keepMap(item => Some(item))
          ->Belt.Array.map(mapToMessage);
        messages
        |> Array.mapi((index, m) =>
             <div className=Styles.dexContainer>
               <div key={index->string_of_int} className=Styles.dex>
                 <h1 className=Styles.dexTitle> m->React.string </h1>
               </div>
             </div>
           )
        |> React.array;

      // | Error(_e) => <text> "Error"->React.string </text>
      | NotFound => <text> "Not Found"->React.string </text>
      | Error(e) =>
        /* this may never be triggered here here because maybe the subscription just listens and does nothing if it recieves no data */
        <HandleError e />
      }
    }
  </SubscriptionWithHandler>;
};