let adderWithPluggableLogger logger x y = 
    logger "x" x |> ignore
    logger "y" y |> ignore
    let result = x + y
    logger "x + y" result |> ignore
    result

let consoleLogger argName argValue = 
    printfn "%s = %A" argName argValue

let popupLogger argName argValue = 
    let message = sprintf "%s = %A" argName argValue
    System.Windows.Forms.MessageBox.Show 
        (text = message, caption = "Logger")
    |> ignore

let addWithConsoleLogger = adderWithPluggableLogger consoleLogger
let addWithPopupLogger = adderWithPluggableLogger popupLogger

addWithConsoleLogger 1 2
addWithConsoleLogger 42 99

addWithPopupLogger 1 2
addWithPopupLogger 42 99

let add42WithConsoleLogger = addWithConsoleLogger 42

[1;2;3] |> List.map add42WithConsoleLogger

let addxy () () () () () () x y = x + y

addxy () () () () () () 1 2