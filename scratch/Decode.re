// [@bs.deriving abstract]
type newMessageSub = {
  id: string,
  message: string,
};
// // type newMessageJs = {messageJs};
// type message = {
//   id: string,
//   message: string,
// };
// type newMessageKey = {
//   id: string,
//   message: string,
// };
type newMessageRespJs = {
  .
  "newMessage": {
    .
    "id": string,
    "message": string,
  },
}; /*   data => {message: data##messageGet, id: data##idGet}*/
// let decode: newMessageJs => newMessage =
// type newMessageResp = {
//   .
//   "newMessage": {
//     .
//     "id": string,
//     "message": string,
//   },
// };

type subscribedMessageResponse = {
  newMessage: newMessageSub
};
let decodeResponse: newMessageRespJs => subscribedMessageResponse =
  data => {
    let id = data##newMessage##id;
    let message = data##newMessage##message;
    let decoded = {
      newMessage: {
        id,
        message,
      },
    };
    decoded;
  };