open System

let a = Console.ReadLine () 
        |> int

let b = (Console.ReadLine ()).Split [|' '|] 
        |> Array.map (fun x -> x |> int) 
        |> Array.toList

let arr = a :: b

let str = Console.ReadLine ()

printfn "%i %s" (arr |> List.sum) str