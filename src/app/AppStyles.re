module Styles = {
  open Css;
  let container =
    style([
      position(absolute),
      display(grid),
      gridTemplateColumns([rem(15.), `fr(1.)]),
      height(pct(100.)),
      width(pct(100.)),
      fontFamily("Roboto"),
    ]);
  let list =
    style([paddingLeft(rem(0.)), margin(rem(-0.5)), overflow(auto)]);

  let listItem =
    style([
      listStyleType(`none),
      padding3(~top=rem(0.5), ~h=rem(0.), ~bottom=rem(0.5)),
      hover([backgroundColor(hex("F29441"))]),
      cursor(`pointer),
    ]);
  let button =
    style([
      color(hex("ffff")),
      backgroundColor(transparent),
      borderColor(transparent),
      fontSize(rem(1.)),
      cursor(`pointer),
      width(pct(100.)),
      textAlign(`left),
    ]);
  let dexTitle =
    style([fontSize(rem(2.)), margin(zero), padding(rem(0.5))]);
  let dexText =
    style([
      display(flexBox),
      flexDirection(column),
      backgroundColor(white),
      width(pct(100.)),
      borderBottomLeftRadius(pct(5.0)),
      borderBottomRightRadius(pct(5.0)),
      borderTop(px(2), solid, hsl(deg(210.), 23., 95.)),
      alignItems(center),
    ]);
  let dex =
    style([
      display(flexBox),
      flexDirection(column),
      width(pct(100.)),
      borderRadius(pct(5.)),
      background(
        linearGradient(
          deg(45.),
          [(zero, hex("F29441")), (pct(100.), hex("A04AD9"))],
        ),
      ),
      border(px(2), solid, hsl(deg(210.), 23., 95.)),
      overflow(hidden),
      alignItems(center),
      boxShadow(
        Shadow.box(
          ~x=px(0),
          ~y=px(0),
          ~blur=px(6),
          hsl(deg(0.), 0., 80.),
        ),
      ),
    ]);
  let dexContainer =
    style([
      display(flexBox),
      alignItems(flexStart),
      justifyContent(center),
      margin(auto),
      width(rem(25.)),
    ]);
};