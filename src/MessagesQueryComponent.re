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

let request = SubscribeNewMessage.make();

/* Pull out message from response. Annotate function as Js.t('a) => string so that react.element can render or else throws error saying type is message. */
let mapToMessage: Js.t('a) => string =
  newNebulaJs => {
    let message = newNebulaJs##newMessage##message;
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
             <div className=AppStyles.dexContainer>
               <div key={index->string_of_int} className=AppStyles.dex>
                 <h1 className=AppStyles.dexTitle> m->React.string </h1>
               </div>
             </div>
           )
        |> React.array;
      | NotFound => <text> "Not Found"->React.string </text>
      | Error(e) =>
        /* this may never be triggered here here because maybe the subscription just listens and does nothing if it recieves no data */
        <HandleError e />
      }
    }
  </SubscriptionWithHandler>;
};