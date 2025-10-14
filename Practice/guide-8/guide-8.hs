-- 1. Union of two sets
unionSet :: (Eq a) => [a] -> [a] -> [a]
unionSet xs ys = xs ++ [y | y <- ys, y `notElem` xs]

-- 2. Intersection of two sets
intersectionSet :: (Eq a) => [a] -> [a] -> [a]
intersectionSet xs ys = [x | x <- xs, x `elem` ys]

-- 3. Difference of two sets (A - B)
differenceSet :: (Eq a) => [a] -> [a] -> [a]
differenceSet xs ys = [x | x <- xs, x `notElem` ys]

-- 4. Symmetric difference between two sets
symmetricDifference :: (Eq a) => [a] -> [a] -> [a]
symmetricDifference xs ys = unionSet (differenceSet xs ys) (differenceSet ys xs)

-- 5. Convert an octal number (base 8) represented as a list to decimal
octalToDecimal :: [Int] -> Int
octalToDecimal ds = sum (zipWith (*) ds (iterate (*8) 1))

-- 6. Convert a number in any base (1 to 10) represented as a list to decimal
toDecimalBase :: Int -> [Int] -> Int
toDecimalBase base ds
  | base < 1 || base > 10 = error "Base must be between 1 and 10"
  | base == 1             = sum ds
  | otherwise             = sum (zipWith (*) ds (iterate (* base) 1))

-- 7. Convert a hexadecimal number (base 16) represented as a list to decimal
hexToDecimal :: [Int] -> Int
hexToDecimal ds
  | all (\d -> d >= 0 && d <= 15) ds = sum (zipWith (*) ds (iterate (*16) 1))
  | otherwise = error "Hex digits must be in range 0..15"

-- 8. Compute the greatest common divisor (GCD) using Euclid's algorithm
gcdEuclid :: (Integral a) => a -> a -> a
gcdEuclid a b
  | b == 0    = abs a
  | otherwise = gcdEuclid b (a `mod` b)

-- 9. Insert an element into a sorted list while keeping it sorted
insertSorted :: (Ord a) => a -> [a] -> [a]
insertSorted x [] = [x]
insertSorted x (y:ys)
  | x <= y    = x : y : ys
  | otherwise = y : insertSorted x ys

-- 10. Sort a list using the insertion sort algorithm
insertionSort :: (Ord a) => [a] -> [a]
insertionSort = foldr insertSorted []

-- 11. Merge two sorted lists into a single sorted list
mergeSorted :: (Ord a) => [a] -> [a] -> [a]
mergeSorted [] bs = bs
mergeSorted as [] = as
mergeSorted (a:as) (b:bs)
  | a <= b    = a : mergeSorted as (b:bs)
  | otherwise = b : mergeSorted (a:as) bs

-- 12. Generate a Fibonacci sequence up to f(n) as a list [0,1,1,2,3,...,f(n)]
fibList :: Int -> [Int]
fibList n
  | n < 0     = error "n must be >= 0"
  | otherwise = take (n + 1) fibs
  where
    fibs :: [Int]
    fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

main :: IO ()
main = do
  putStrLn "Example outputs:"
  print (unionSet [1,2,3] [3,4,5])
  print (intersectionSet [1,2,3] [2,3,4])
  print (differenceSet [1,2,3,4] [2,3])
  print (symmetricDifference [1,2,3] [3,4,5])
  print (octalToDecimal [7,2,1])
  print (toDecimalBase 8 [7,2,1])
  print (hexToDecimal [15,10,1])
  print (gcdEuclid 48 18)
  print (insertSorted 3 [1,2,5,7])
  print (insertionSort [3,1,4,2])
  print (mergeSorted [1,3,5] [2,4,6])
  print (fibList 10)
