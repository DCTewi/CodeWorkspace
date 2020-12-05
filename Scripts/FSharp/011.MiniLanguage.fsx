type DateScale =
    | Hour
    | Hours
    | Day
    | Days
    | Week
    | Weeks

type DateDirection = Ago | Hence

let fromNow interval scale direction =
    let absHours = match scale with
                   | Hour | Hours -> 1 * interval
                   | Day  | Days -> 24 * interval
                   | Week | Weeks -> 24 * 7 * interval
    let signedHours = match direction with
                      | Ago -> -1 * absHours
                      | Hence -> absHours
    signedHours |> float |> System.DateTime.Now.AddHours

let time1 = fromNow 5 Days Ago
let time2 = fromNow 1 Hour Hence


type FluentShape = 
    {
        Label: string
        Color: string
        OnClick: FluentShape -> FluentShape
    }

let defaultShape = 
    {
        Label = ""
        Color = ""
        OnClick = fun s -> s
    }

let click shape = 
    shape.OnClick shape

let display shape =
    printfn "My label = %s and my color = %s" shape.Label shape.Color
    shape

let setLabel label shape =
    {
        shape with
            FluentShape.Label = label
    }

let setColor color shape =
    {
        shape with
            FluentShape.Color = color
    }

let appendClickAction action shape =
    {
        shape with
            FluentShape.OnClick = shape.OnClick >> action
    }

let setRedBox = setColor "red" >> setLabel "box"
let setBlueBox = setRedBox >> setColor "blue"
let changeColorOnclick color = appendClickAction (setColor color)

let redBox = defaultShape |> setRedBox
let blueBox = defaultShape |> setBlueBox

redBox
    |> display
    |> changeColorOnclick "green"
    |> click
    |> display

blueBox
    |> display
    |> appendClickAction (setLabel "box2" >> setColor "green")
    |> click
    |> display

let rainbow =
    ["red"; "orange"; "yellow"; "green"; "blue"; "indigo"; "violet"]

let showRainbow = 
    let setColorAndDisplay color = setColor color >> display
    rainbow
    |> List.map setColorAndDisplay
    |> List.reduce (>>)

defaultShape |> showRainbow
