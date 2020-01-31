open ReasonUrql;
[@react.component]
let make = (~e: UrqlCombinedError.t) => {
  switch (e) {
  | {networkError: Some(ne)} =>
    <div>
      {ne
       ->Js.Exn.message
       ->Belt.Option.getWithDefault("Network error")
       ->React.string}
    </div>
  | {graphQLErrors: Some(gqle)} =>
    <div>
      {gqle
       |> Array.to_list
       |> List.map(e => {
            let msg =
              Belt.Option.getWithDefault(
                Js.Nullable.toOption(CombinedError.messageGet(e)),
                "GraphQL error",
              );
            "[GraphQLError: " ++ msg ++ "]";
          })
       |> String.concat(", ")
       |> React.string}
    </div>
  | _ => <div> "Unknown error."->React.string </div>
  };
};