[@react.component]
let make = () =>
  <div
    className=Css.(
      style([
        display(`grid),
        gridTemplateColumns([`repeat((`num(2), `fr(1.)))]),
        gridGap(10->px),
      ])
    )>
    <div>
      <h1 className=AppStyles.dexText>
        "Subscription with Component"->React.string
      </h1>
      <MessagesQueryComponent />
    </div>
    <div>
      <h1 className=AppStyles.dexText>
        "Subscription with Hooks"->React.string
      </h1>
      <NebulaHooks />
    </div>
  </div>;