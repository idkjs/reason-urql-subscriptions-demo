const { PubSub } = require("graphql-subscriptions");
const { HarryPotter,Space } = require("fakergem");

const pubsub = new PubSub();

const store = {
  messages: [],
  nebulas: [],
  numbers: [],
  floats: []
};

const typeDefs = `
type Query {
  messages: [Message!]!
  nebulas: [Nebula!]!
  numbers: [Int!]!
  floats: [Float!]!
}
type Subscription {
  newMessage: Message!
  newNebula: Nebula!
  newNumber: Int!
  newFloat: Float!
}
type Message {
  id: ID!,
  message: String!,
}
type Nebula {
  id: ID!,
  message: String!,
}
`;

const resolvers = {
  Query: {
    messages: store.messages,
    nebulas: store.nebulas,
    numbers: store.numbers,
    floats: store.floats
  },
  Subscription: {
    newMessage: {
      subscribe: () => pubsub.asyncIterator("newMessage")
    },
    newNebula: {
      subscribe: () => pubsub.asyncIterator("newNebula")
    },
    newNumber: {
      subscribe: () => pubsub.asyncIterator("newNumber")
    },
    newFloat: {
      subscribe: () => pubsub.asyncIterator("newFloat")
    }
  }
};

module.exports = {
  typeDefs,
  resolvers,
  context: (headers, secrets) => {
    return {
      headers,
      secrets
    };
  }
};

let id = 0;

setInterval(() => {
  const newMessage = {
    id: ++id,
    message: HarryPotter.quote()
  };

  pubsub.publish("newMessage", {
    newMessage
  });
}, 5000);
setInterval(() => {
  const newNebula = {
    id: ++id,
    message: Space.nebula()
  };

  pubsub.publish("newNebula", {
    newNebula
  });
}, 5000);

function getRandomInt(max) {
  return Math.floor(Math.random() * Math.floor(max));
}

setInterval(() => {
  pubsub.publish("newNumber", {
    newNumber: getRandomInt(1000)
  });
}, 2000);

setInterval(() => {
  pubsub.publish("newFloat", {
    newFloat: Math.random() * 1000
  });
}, 500);
