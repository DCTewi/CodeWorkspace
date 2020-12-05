// single line comments
(*
    multi line comments
*)

//== Values

let myInt = 5
let myFloat = 3.14
let myString = "Hello"

//== Lists

let two2Four = [
    2
    3
    4
]
let two2Five = [2;3;4;5]
let one2Five = 1 :: two2Five
let zero2Five = [0;1] @ two2Five

//== Functions
let square x = x * x
square 3

let add x y = x + y 
add 2 3

let evens list =
    let isEven x = x % 2 = 0
    List.filter isEven list
evens one2Five

let sumOfSquaresTo100 = 
    List.sumBy square [1..100]

let sumOfSquaresTo100Piped = 
    [1..100] 
    |> List.sumBy square

let sumOfSquaresTo100WithFun = 
    [1..100]
    |> List.sumBy (fun x -> x * x)

//== Pattern Matching

let simplePatternMatch = 
    let x = "a"
    match x with
    | "a" -> printfn "A"
    | "b" -> printfn "B"
    | _ -> printfn "other"

// "Nullable wrapper"
let validValue =  Some 100
let invalidValue = None

let optionPatternMatch input = 
    match input with
    | Some i -> printfn "input is an int = %d" i
    | None -> printfn "input is missing"
optionPatternMatch validValue
optionPatternMatch invalidValue

//== Complex Data Types

// Tuple
let twoTuple = 1, 2
let threeTuple = "a", 1, true

// Record
type Person = { First: string; Last: string }
let person1 = 
    {
        First = "John"
        Last = "Doe"
    }

// Union
type Temp = 
    | DegreeC of float
    | DegreeF of float
let temp = DegreeF 98.6

// rec type 
type Employee = 
    | Worker of Person
    | Manager of Employee list
let joe = { First = "joe"; Last = "doe" }
let worker = Worker joe

//== Printing
printfn "Printing int %i float %f bool %b" 1 2.0 true
printfn "string %s generic %A" "Hello" [1;2;3;4]

printfn "%A %A %A %A" twoTuple person1 temp worker
