# ReasonUrql Subscription Component and Subscription Hooks

## Building

This project uses [reason-urql](https://github.com/FormidableLabs/reason-urql) from git which was tricky for me to work with. To get it to run I had to `cd node_modules/reason-urql` then run `yarn install && yarn build`.

```sh
$ yarn install
$ cd server && yarn install
$ cd node_modules/reason-urql && yarn install && yarn build
```

App will be on `http://localhost:4000/`.
Graphiql will be on `http://localhost:4000/graphql`.

## Why

This demos reading subscription responses with `reason-urql`'s query components, in [./src/app/Messages.re](./src/app/Messages.re) and hooks in [./src/app/MessagesHooks.re](./src/app/MessagesHooks.re).

This repo is basically a note to self on using graphql subscription's with [Reason](https://reasonml.github.io/).

Most of the code comes from the [reason-urql examples](https://github.com/FormidableLabs/reason-urql/examples) and has been mashed up for my learning purposes.
