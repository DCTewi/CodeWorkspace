type Stack = StackContents of float list

let newStack = StackContents [1.0; 2.0; 3.0]

// let (StackContents contents) = newStack
// to get contents

//let push x aStack =
//    let (StackContents contents) = aStack
//    let newContents = x :: contents
//    StackContents newContents

let push x (StackContents contents) = 
    StackContents (x :: contents)

let ONE = push 1.0 
let TWO = push 2.0
let THREE = push 3.0
let FOUR = push 4.0
let FIVE = push 5.0

let EMPTY = StackContents []

let stackWith1 = ONE EMPTY
let stackWith2 = TWO stackWith1

let result123 = EMPTY |> ONE |> TWO |> THREE
let result312 = EMPTY |> THREE |> ONE |> TWO

let pop (StackContents contents) =
    match contents with
    | top :: rest ->
        let newStack = StackContents rest
        (top, newStack)
    | [] ->
        failwith "Stack underflow"

//let ADD stack = 
//    let x, s = pop stack
//    let y, s2 = pop s
//    let res = x + y
//    push res s2

//let MUL stack =
//    let x, s = pop stack
//    let y, s2 = pop s
//    let res = x * y
//    push res s2

let binaryOperator operatorFn stack = 
    let y, stack' = pop stack
    let x, stack'' = pop stack'
    let z = operatorFn x y
    push z stack''

let unaryOperator operatorFn stack =
    let x, stack' = pop stack
    push (operatorFn x) stack'

let ADD = binaryOperator (+)
let MUL = binaryOperator (*)
let SUB = binaryOperator (-)
let DIV = binaryOperator (/)

let NEG = unaryOperator (fun x -> -x)
//let SQUARE = unaryOperator (fun x -> x * x)
let SQRT = unaryOperator (fun x -> sqrt x)

let SHOW stack = 
    let x, _ = pop stack
    printfn "The answer is %f" x
    stack

let DUP stack = 
    let x, _ = pop stack
    push x stack

let SWAP stack =
    let x, s = pop stack
    let y, s' = pop s
    push y (push x s')

let START = EMPTY

let ONE_TWO_ADD = 
    ONE >> TWO >> ADD 

let SQUARE = 
    DUP >> MUL 

let CUBE = 
    DUP >> DUP >> MUL >> MUL 

let SUM_NUMBERS_UPTO = 
    DUP      // n, n 2 items on stack
    >> ONE   // n, n, 1 3 items on stack 
    >> ADD   // n, (n+1) 2 items on stack
    >> MUL   // n(n+1) 1 item on stack
    >> TWO   // n(n+1), 2 2 items on stack 
    >> DIV   // n(n+1)/2 1 item on stack


let initStack = EMPTY |> ONE |> TWO
let p1, ps1 = pop initStack
let p2, ps2 = pop ps1
let _ = pop EMPTY

let add1and2 = EMPTY |> ONE |> TWO |> ADD
let add2and3 = EMPTY |> TWO |> THREE |> ADD
let mult2and3 = EMPTY |> TWO |> THREE |> MUL
let threeDivTwo = EMPTY |> THREE |> TWO |> DIV
let oneAddTwoSubThree = EMPTY |> ONE |> TWO |> ADD |> THREE |> SUB

let neg3 = EMPTY |> THREE |> NEG
let square2 = EMPTY |> TWO |> SQUARE
let sqrt2 = EMPTY |> TWO |> SQRT

EMPTY |> ONE |> THREE |> ADD |> TWO |> MUL |> SHOW // (1+3)*2 = 8

START
    |> ONE |> TWO |> SHOW

START
    |> ONE |> TWO |> ADD |> SHOW 
    |> THREE |> ADD |> SHOW 

START
    |> THREE |> DUP |> DUP |> MUL |> MUL // 27

START
    |> ONE |> TWO |> ADD |> SHOW  // 3
    |> THREE |> MUL |> SHOW       // 9
    |> TWO |> DIV |> SHOW         // 9 div 2 = 4.5

START |> TWO |> SQUARE |> SHOW

START |> THREE |> CUBE |> SHOW

START |> THREE |> SQUARE |> SUM_NUMBERS_UPTO |> SHOW  // 45