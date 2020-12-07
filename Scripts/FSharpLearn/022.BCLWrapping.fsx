let replace oldValue newValue (s: string) = 
    s.Replace (oldValue=oldValue, newValue=newValue)

let startsWith lookFor (s: string) =
    s.StartsWith lookFor

let split notations (s: string) =
    s.Split (notations)

let trim (s: string) = 
    s.Trim ()

let result = 
    "hello world, this is a new world, nice to meet you"
    |> replace "h" "t"
    |> split [|','|]
    |> Array.map (fun x -> x |> trim)
    |> Array.filter (fun x -> x |> startsWith "t")

let (|>) x f = f x 

"12" |> int
1 |> (+) 2 |> (*) 3

let (<|) f x = f x





let ``one hundred and twenty three`` = 123
let f x = pown x 2
let f' x = x
let f'' _ = 1

printfn "%i" <| f ``one hundred and twenty three``
printfn "%i" <| f' ``one hundred and twenty three``
printfn "%i" <| f'' ``one hundred and twenty three``


let sum list = 
    List.reduce (fun sum e -> printfn "%i %i" sum e; sum + e) list

let sumPointFree = 
    List.reduce (+)

sum [2;4;6;7;8;9] |> printfn "sum = %i"
sumPointFree [2;4;6;7;8;9] |> printfn "sum = %i"


let (~~) (s: string) = s.Trim ()
let (~%%) (s: string) = s.ToCharArray ()

let trimed = ~~" hello world   "
let chararr = %% "hello"
