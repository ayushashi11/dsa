use std::{mem, marker::PhantomData};
#[derive(Debug, Clone)]
pub struct List<T> {
    head: Link<T>,
}

type Link<T> = Option<Box<Node<T>>>;

#[derive(Debug, Clone)]
struct Node<T> {
    elem: T,
    next: Link<T>,
}
impl<T:Clone+std::fmt::Debug> List<T> {
    pub fn new() -> Self {
        List { head: None }
    }

    pub fn push(&mut self, elem: T) {
        let new_node = Box::new(Node {
            elem: elem,
            next: self.head.take(),
        });

        self.head = Some(new_node);
    }

    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            node.elem
        })
    }
    pub fn peek_mut(&mut self) -> Option<&mut T> {
        self.head.as_mut().map(|node| {
            &mut node.elem
        })
    }
    pub fn peek_mut_at(&mut self, index: isize) -> Option<&mut T>{
        self.head.as_mut().map(|node|{
            let mut curr = node;
            let mut i=0;
            while(i<index) {curr = match curr.next.as_mut(){
                Some(v) => v,
                None => panic!("index out of bounds")
            };
            i+=1;
            }
            &mut curr.elem
        })
    }
    
}

impl<T> Drop for List<T> {
    fn drop(&mut self) {
        let mut cur_link = self.head.take();
        while let Some(mut boxed_node) = cur_link {
            cur_link = boxed_node.next.take();
        }
    }
}

fn main(){
    let mut v = List::new();
    v.push(4);
    v.push(5);
    if let Some(k) = v.peek_mut_at(1){
        *k=6;
    }
    println!("{:?}",v);
}