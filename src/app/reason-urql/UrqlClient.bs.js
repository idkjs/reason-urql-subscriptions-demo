// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Urql from "urql";
import * as Block from "bs-platform/lib/es6/block.js";
import * as Wonka from "wonka/src/wonka.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_mapperRt from "bs-platform/lib/es6/js_mapperRt.js";
import * as UrqlCombinedError from "./utils/UrqlCombinedError.bs.js";

function unwrapFetchOptions(fetchOptions) {
  if (fetchOptions !== undefined) {
    var match = fetchOptions;
    if (match.tag) {
      return match[0];
    } else {
      return Caml_option.some(match[0]);
    }
  }
  
}

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -616602076,
    "teardown"
  ],
  /* tuple */[
    -250086680,
    "query"
  ],
  /* tuple */[
    -32289987,
    "subscription"
  ],
  /* tuple */[
    1035765577,
    "mutation"
  ]
];

function operationTypeToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray);
}

function operationTypeFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray, param);
}

var jsMapperConstantArray$1 = /* array */[
  /* tuple */[
    3604019,
    "hit"
  ],
  /* tuple */[
    859143964,
    "miss"
  ],
  /* tuple */[
    939392865,
    "partial"
  ]
];

function cacheOutcomeToJs(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$1);
}

function cacheOutcomeFromJs(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$1, param);
}

var ClientTypes = {
  operationTypeToJs: operationTypeToJs,
  operationTypeFromJs: operationTypeFromJs,
  cacheOutcomeToJs: cacheOutcomeToJs,
  cacheOutcomeFromJs: cacheOutcomeFromJs
};

var UrqlExchanges = { };

function make(url, fetchOptions, $staropt$star, $staropt$star$1, param) {
  var exchanges = $staropt$star !== undefined ? $staropt$star : /* array */[
      Urql.dedupExchange,
      Urql.cacheExchange,
      Urql.fetchExchange
    ];
  var suspense = $staropt$star$1 !== undefined ? $staropt$star$1 : false;
  return new Urql.Client({
              url: url,
              fetchOptions: unwrapFetchOptions(fetchOptions),
              exchanges: exchanges,
              suspense: suspense
            });
}

function urqlClientResponseToReason(parse, result) {
  var data = Belt_Option.map(Caml_option.nullable_to_opt(result.data), parse);
  var error = Belt_Option.map(Caml_option.nullable_to_opt(result.error), UrqlCombinedError.combinedErrorToRecord);
  var response = data !== undefined ? /* Data */Block.__(0, [Caml_option.valFromOption(data)]) : (
      error !== undefined ? /* Error */Block.__(1, [error]) : /* NotFound */0
    );
  return /* record */[
          /* data */data,
          /* error */error,
          /* response */response
        ];
}

function executeQuery(client, request, opts, param) {
  var req = Urql.createRequest(request.query, request.variables);
  var parse = request.parse;
  return Wonka.map((function (result) {
                  return urqlClientResponseToReason(parse, result);
                }))(client.executeQuery(req, opts !== undefined ? Caml_option.valFromOption(opts) : undefined));
}

function executeMutation(client, request, opts, param) {
  var req = Urql.createRequest(request.query, request.variables);
  var parse = request.parse;
  return Wonka.map((function (result) {
                  return urqlClientResponseToReason(parse, result);
                }))(client.executeMutation(req, opts !== undefined ? Caml_option.valFromOption(opts) : undefined));
}

function executeSubscription(client, request, opts, param) {
  var req = Urql.createRequest(request.query, request.variables);
  var parse = request.parse;
  return Wonka.map((function (result) {
                  return urqlClientResponseToReason(parse, result);
                }))(client.executeSubscription(req, opts !== undefined ? Caml_option.valFromOption(opts) : undefined));
}

function createRequestOperation(client, operationType, request, opts, param) {
  var op = Js_mapperRt.binarySearch(4, operationType, jsMapperConstantArray);
  return client.createRequestOperation(op, request, opts !== undefined ? Caml_option.valFromOption(opts) : undefined);
}

export {
  unwrapFetchOptions ,
  ClientTypes ,
  UrqlExchanges ,
  make ,
  urqlClientResponseToReason ,
  executeQuery ,
  executeMutation ,
  executeSubscription ,
  createRequestOperation ,
  
}
/* urql Not a pure module */