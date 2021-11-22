data Maybe a = Nothing | Just a

instance Functor Maybe where
  fmap f (Just a) = Just (f a)
  fmap _ Nothing = Nothing

instance Applicative Maybe where
  pure = Just
  Just f <*> x = fmap f x
  Nothing <*> _ = Nothing

instance Monad Maybe where
  return = Just
  (Just a) >>= f = f x
  Nothing >>= _ = Nothing

data MyEither a b = MyLeft a | MyRight b | None
  deriving (Eq, Show)

instance Functor (MyEither e) where
  fmap f (MyLeft a) = MyLeft a
  fmap f (MyRight b) = MyRight (f b)
  fmap _ None = None

instance Applicative (MyEither e) where
  pure = MyRight
  MyLeft e <*> _ = MyLeft e
  MyRight f <*> r = fmap f r
  None <*> _ = None

instance Monad (MyEither e) where
  return = MyRight
  (MyLeft a) >>= _ = MyLeft a
  (MyRight b) >>= f = MyRight (f b)
  None >>= _ = None

data MyTree a = MyLeaf a | MyNode (MyTree a) (MyTree a)
  deriving (Eq, Show)

instance Functor MyTree where
  fmap f (MyLeaf a) = MyLeaf (f a)
  fmap f (MyNode l r) = Mynode (fmap f l) (fmap f r)

instance Applicative MyTree where
  pure = MyLeaf
  MyLeaf f <*> r = fmap f r
  MyNode f1 f2 <*> MyLeaf a = MyNode (f1 a) (f2 a)
  MyNode f1 f2 <*> MyNode l r = MyNode (f1 l) (f2 r)

instance Monad MyTree where
  return = MyLeaf
  MyLeaf a >>= f = MyLeaf (f a)
  MyNode l r >>= f = MyNode (f >>= l) (f >>= r)

process :: String -> Maybe [Int]
process filename =
  case readData filename of
    Nothing -> Nothing
    Just rawLines ->
      case parseData rawLines of
        Nothing -> Nothing
        Just parsed ->
          case processData parsed of
            Nothing -> Nothing
            Just proccessed -> return processed

process :: String -> Maybe [Int]
process filename = do
  rawLines <- readData filename
  parsed <- parseData rawLines
  processed <- processData parsed
  return processed