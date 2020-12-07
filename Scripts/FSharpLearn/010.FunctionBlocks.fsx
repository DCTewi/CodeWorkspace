let add2 x = x + 2
let mul3 x = x * 3
let square x = x * x

[1..10] |> List.map add2 |> printfn "%A"
[1..10] |> List.map mul3 |> printfn "%A"
[1..10] |> List.map square |> printfn "%A"

let add2ThenMul3 = add2 >> mul3
let mul3ThenSquare = mul3 >> square

[1..10] |> List.map add2ThenMul3 |> printfn "%A"
[1..10] |> List.map mul3ThenSquare |> printfn "%A"

let logMsg msg x = printf "%s%i" msg x; x
let logMsgN msg x = printfn "%s%i" msg x; x

let mul3ThenSquareLogged = 
    logMsg "Before = "
    >> mul3
    >> logMsg " agter mult3 = "
    >> square
    >> logMsgN " result = "

[1..10] |> List.map mul3ThenSquareLogged |> printfn "%A"

let functionSeq = 
    [
        mul3
        square
        add2
        logMsgN "result="
    ]
let allFunc = List.reduce (>>) functionSeq
allFunc 5

