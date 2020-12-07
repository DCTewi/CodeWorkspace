/// Types

type Stack = StackContents of float list

/// Stack Primitives

let push x (StackContents contents) =
    StackContents (x :: contents)

let pop (StackContents contents) =
    match contents with
    | top :: rest ->
        let newStack = StackContents rest
        (top, newStack)
    | [] ->
        failwith "Stack underflow"

/// Operator Core

let binaryOperator op stk =
    let y, stk' = pop stk
    let x, stk'' = pop stk'
    let z = op x y
    push z stk''

let unaryOperator op stk = 
    let x, stk' = pop stk
    push (op x) stk'

/// Other Core

let SHOW stack = 
    let x,_ = pop stack
    printfn "The answer is %f" x
    stack

let DUP stack = 
    let x,s = pop stack  
    push x (push x s)   
    
let SWAP stack = 
    let x,s = pop stack  
    let y,s' = pop s
    push y (push x s')   

let DROP stack = 
    let _,s = pop stack
    s

/// WordBased Primitives

// Constants
// -------------------------------
let EMPTY = StackContents []
let START  = EMPTY


// Numbers
// -------------------------------
let ONE = push 1.0
let TWO = push 2.0
let THREE = push 3.0
let FOUR = push 4.0
let FIVE = push 5.0

// Math functions
// -------------------------------
let ADD = binaryOperator (+)
let SUB = binaryOperator (-)
let MUL = binaryOperator (*)
let DIV = binaryOperator (/)

let NEG = unaryOperator (fun x -> -x)

/// WordBased Composition

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