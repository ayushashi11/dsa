#![feature(box_patterns)]
#![feature(box_syntax)]
use std::cmp::max;
#[derive(Clone)]
enum Tree<T: Clone>{
    Nil,
    Node(T, Box<Tree<T>>, Box<Tree<T>>)
}
use Tree::*;
fn height<T: Clone>(t: Tree<T>) -> i64{
    match t{
        Nil => -1,
        Node(_, box a, box b) => 1+max(height(a), height(b))
    }
}
fn balance<T:Clone>(t: Tree<T>) -> i64{
    if let Node(_, box a, box b) = t {
        (height(a)-height(b)).abs()
    }
    else{
        0
    }
}
fn main() {
    let t = Node(
        1,
        Box::new(Node(
            2,
            Box::new(Node(
                4,
                Box::new(Nil),
                Box::new(Nil)
            )),
            Box::new(Nil)
        )),
        Box::new(Node(
            3,
            Box::new(Nil),
            Box::new(Nil)
            // Box::new(Node(
            //     5,
            //     Box::new(Nil),
            //     Box::new(Nil)
            // ))
        ))
    );
    println!("{}", height(t.clone()));
    println!("{}", balance(t));
}
