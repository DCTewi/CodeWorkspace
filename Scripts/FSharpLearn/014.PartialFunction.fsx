let add x y = x + y

let z = add 1 2

let add42 = add 42

add42 3


let genericLogger before after anyFunc input =
    before input
    let result = anyFunc input
    after result
    result

let add1 input = input + 1

(add1, 2)
||> genericLogger
    (fun x -> printf "before = %i. " x)
    (fun x -> printfn "after = %i. " x)

2
|>((
    (fun x -> printf "before = %i. " x),
    (fun x -> printfn "after = %i. " x),
    add1
)
|||> genericLogger)

let add1WithConsoleLogging = 
    (
        (fun x -> printf "before = %i. " x),
        (fun x -> printfn "after = %i. " x),
        add1
    )
    |||> genericLogger

add1WithConsoleLogging 2

[1..5] |> List.map add1WithConsoleLogging