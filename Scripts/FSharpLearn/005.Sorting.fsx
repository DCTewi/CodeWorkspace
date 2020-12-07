let rec quicksort list =
    match list with
    | [] -> []
    | mid::other ->
        let l = 
            other
            |> List.filter (fun e -> e < mid)
            |> quicksort
        let r = 
            other
            |> List.filter (fun e -> e >= mid)
            |> quicksort
        List.concat [l; [mid]; r]

printfn "%A" (quicksort [6;4;5;76;1;1;5;67;16;1;43])

let rec qsort = function
                | [] -> []
                | mid::rest ->
                    let l, r = List.partition ((>=) mid) rest
                    List.concat [qsort l; [mid]; qsort r]

printfn "%A" (qsort [6;4;5;76;1;1;5;67;16;1;43])