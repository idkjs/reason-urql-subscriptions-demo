// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Css from "bs-css/src/Css.js";

var container = Css.style(/* :: */[
      Css.position(Css.absolute),
      /* :: */[
        Css.display(Css.grid),
        /* :: */[
          Css.gridTemplateColumns(/* :: */[
                Css.rem(15),
                /* :: */[
                  /* `fr */[
                    22860,
                    1
                  ],
                  /* [] */0
                ]
              ]),
          /* :: */[
            Css.height(Css.pct(100)),
            /* :: */[
              Css.width(Css.pct(100)),
              /* :: */[
                Css.fontFamily("Roboto"),
                /* [] */0
              ]
            ]
          ]
        ]
      ]
    ]);

var aside = Css.style(/* :: */[
      Css.display(Css.flexBox),
      /* :: */[
        Css.flexDirection(Css.column),
        /* :: */[
          Css.height(Css.pct(100)),
          /* :: */[
            Css.backgroundColor(Css.hex("F25050")),
            /* :: */[
              Css.padding(Css.rem(0.5)),
              /* :: */[
                Css.overflow(Css.auto),
                /* :: */[
                  Css.boxSizing(/* borderBox */9307263),
                  /* [] */0
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var search = Css.style(/* :: */[
      Css.marginBottom(Css.rem(1)),
      /* :: */[
        Css.padding(Css.rem(0.5)),
        /* :: */[
          Css.border(Css.rem(0), /* none */-922086728, Css.transparent),
          /* [] */0
        ]
      ]
    ]);

var list = Css.style(/* :: */[
      Css.paddingLeft(Css.rem(0)),
      /* :: */[
        Css.margin(Css.rem(-0.5)),
        /* :: */[
          Css.overflow(Css.auto),
          /* [] */0
        ]
      ]
    ]);

var listItem = Css.style(/* :: */[
      Css.listStyleType(/* none */-922086728),
      /* :: */[
        Css.padding3(Css.rem(0.5), Css.rem(0), Css.rem(0.5)),
        /* :: */[
          Css.hover(/* :: */[
                Css.backgroundColor(Css.hex("F29441")),
                /* [] */0
              ]),
          /* :: */[
            Css.cursor(/* pointer */-786317123),
            /* [] */0
          ]
        ]
      ]
    ]);

var button = Css.style(/* :: */[
      Css.color(Css.hex("ffff")),
      /* :: */[
        Css.backgroundColor(Css.transparent),
        /* :: */[
          Css.borderColor(Css.transparent),
          /* :: */[
            Css.fontSize(Css.rem(1)),
            /* :: */[
              Css.cursor(/* pointer */-786317123),
              /* :: */[
                Css.width(Css.pct(100)),
                /* :: */[
                  Css.textAlign(/* left */-944764921),
                  /* [] */0
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var Styles = {
  container: container,
  aside: aside,
  search: search,
  list: list,
  listItem: listItem,
  button: button
};

export {
  Styles ,
  
}
/* container Not a pure module */