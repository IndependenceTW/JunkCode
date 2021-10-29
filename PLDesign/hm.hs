myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail [a] = []
myTail (a:as) = as

myLast :: [a] -> a
myLast [] = error "empty list"
myLast [a] = a
myLast (a:as) = myLast as

myReverse :: [a] -> [a]
myReverse [] = []
myReverse [a] = [a]
myReverse (a:as) = myReverse as ++ [a]

isPalindrome :: Eq a => [a] -> Bool
isPalindrome as = as == myReverse as

isPalindrome' :: Eq a => [a] -> Bool 
isPalindrome' [] = True 
isPalindrome' [a] = True
isPalindrome' as = (head as == last as) && (isPalindrome' (tail (init as)))