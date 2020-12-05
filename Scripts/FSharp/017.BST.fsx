type BST<'T> = 
    | Empty
    | Node of value: 'T * left: BST<'T> * right: BST<'T>

let rec exists item bst =
    match bst with
    | Empty -> false
    | Node (x, left, right) ->
        if item = x then true
        elif item < x then (exists item left)
        else (exists item right)

let rec insert item bst = 
    match bst with
    | Empty -> Node(item, Empty, Empty)
    | Node(x, left, right) as node ->
        if item = x then node
        elif item < x then Node(x, insert item left, right)
        else Node(x, left, insert item right)

Empty
    |> insert 5
    |> insert 3
    |> exists 5
