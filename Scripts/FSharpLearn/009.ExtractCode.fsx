let product n =
    let initValue = 1
    let action productSoFar x = productSoFar * x
    [1..n] |> List.fold action initValue

product 10

let sumOfOdds n =
    let initValue = 0
    let action sumSoFar x = 
        if x % 2 = 0 then sumSoFar
        else sumSoFar + x
    [1..n] |> List.fold action initValue

sumOfOdds 10

let alternatingSum n =
    let initValue = true, 0
    let action (isNeg, sumSoFar) x =
        if isNeg then (false, sumSoFar - x)
        else (true, sumSoFar + x)
    [1..n] |> List.fold action initValue |> snd

alternatingSum 100

type NumberAndSize = { Name: string; Size: int}

let maxNameAndSize lst =
    let innerMaxNameAndSize initValue rest = 
        let action maxSoFar x =
            if maxSoFar.Size < x.Size then x else maxSoFar
        rest |> List.fold action initValue

    match lst with
    | [] -> None
    | l :: rest ->
        innerMaxNameAndSize l rest |> Some

let list = 
    [
        { Name = "Alice"; Size = 10 }
        { Name = "Bob"; Size = 1 }
        { Name = "Carol"; Size = 12 }
        { Name = "David"; Size = 5 }
    ]

printfn "%A" (maxNameAndSize list)
printfn "%A" (maxNameAndSize [])

let maxNameAndSize2 lst =
    match lst with
    | [] -> None
    | _ -> lst |> List.maxBy (fun x -> x.Size) |> Some

printfn "%A" (maxNameAndSize2 list)
printfn "%A" (maxNameAndSize2 [])
