module Main where
data Tree a = Nil | Node a (Tree a) (Tree a) 

height :: (Num p, Ord p) => Tree a -> p
height Nil = -1
height (Node _ a b) = 1 + max (height a) (height b)

balance :: (Num p, Ord p) => Tree a -> p
balance Nil = 0
balance (Node _ a b) = abs(height a - height b)
 
main :: IO ()
main = do
    let x = Node 1 (Node 2 (Node 4 Nil Nil) Nil) (Node 3 Nil (Node 5 Nil Nil)) --Nil)
    print (height x)
    print (balance x)
