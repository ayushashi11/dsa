use std::fmt::{Display,Debug};

use rand::Rng;

fn merge_sort<T>(v: Vec<T>) ->  Vec<T> where T:Clone+PartialOrd+Display+Debug{
    if v.len()<=1{return v}
    let mid=v.len()/2;
    let mut newv = Vec::with_capacity(v.len());
    newv.resize(v.len(), v[0].clone());
    let (left,right)=v.split_at(mid);
    let sortedleft = merge_sort(left.to_vec());
    let sortedright = merge_sort(right.to_vec());
    let [mut i, mut j, mut k]=[0,0,0];
    let [imax,jmax]=[sortedleft.len(),sortedright.len()];
    while i<imax && j<jmax{
        if sortedleft[i]<sortedright[j]{
            newv[k] = sortedleft[i].clone();
            i+=1;
        }
        else{
            newv[k] = sortedright[j].clone();
            j+=1;
        }
        k+=1;
    }
    while i<imax{
        newv[k] = sortedleft[i].clone();
        i+=1;
        k+=1;
    }
    while j<jmax{
        newv[k] = sortedright[j].clone();
        j+=1;
        k+=1;
    }
    newv
}
fn main(){
    let rawv = [0; 10];
    let mut rng=rand::thread_rng();
    let v = rawv.map(|_|{rng.gen_range(0..100)}).to_vec();
    println!("{:?}",v);
    let v2 = merge_sort(v);
    println!("{:?}",v2);
}