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
      <h1 className=AppStyles.Styles.dexText>
        "src/Messages.Re"->React.string
      </h1>
      <Messages />
    </div>
    <div>
      <h1 className=AppStyles.Styles.dexText>
        "src/MessagesHooks.Re"->React.string
      </h1>
      <MessagesHooks />
    </div>
  </div>;