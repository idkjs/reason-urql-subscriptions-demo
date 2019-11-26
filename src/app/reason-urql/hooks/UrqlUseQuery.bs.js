// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Urql from "urql";
import * as Block from "bs-platform/lib/es6/block.js";
import * as React from "react";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as UrqlCombinedError from "../utils/UrqlCombinedError.bs.js";

function useQuery(request, requestPolicy, pause, param) {
  var tmp = {
    query: request.query,
    variables: request.variables
  };
  if (requestPolicy !== undefined) {
    tmp.requestPolicy = Caml_option.valFromOption(requestPolicy);
  }
  if (pause !== undefined) {
    tmp.pause = Caml_option.valFromOption(pause);
  }
  var args = tmp;
  var match = Urql.useQuery(args);
  var responseJs = match[0];
  var response = React.useMemo((function () {
          var parse = request.parse;
          var result = responseJs;
          var data = Belt_Option.map(Caml_option.nullable_to_opt(result.data), parse);
          var error = Belt_Option.map(Caml_option.undefined_to_opt(result.error), UrqlCombinedError.combinedErrorToRecord);
          var fetching = result.fetching;
          var response = fetching ? /* Fetching */0 : (
              error !== undefined ? /* Error */Block.__(1, [error]) : (
                  data !== undefined ? /* Data */Block.__(0, [Caml_option.valFromOption(data)]) : /* NotFound */1
                )
            );
          return /* record */[
                  /* fetching */fetching,
                  /* data */data,
                  /* error */error,
                  /* response */response
                ];
        }), /* tuple */[
        responseJs,
        request.parse
      ]);
  return /* tuple */[
          response,
          match[1]
        ];
}

export {
  useQuery ,
  
}
/* urql Not a pure module */
