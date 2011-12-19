
module Main where

import Data.List
import Control.Applicative
import Control.Monad

import System.Environment
import System.Process

main :: IO ()
main = do
    args <- getArgs
    case args of
        name : _ -> main' name
        _ -> return ()

latexsc :: String -> IO () -> IO ()
latexsc option action = do
    putStrLn $ "\\begin{lstlisting}[" ++ option ++ "]"
    action
    putStrLn $ "\\end{lstlisting}"

main' :: String -> IO ()
main' name = do
    putStrLn "\\subsection{ソースコード}"
    latexsc "style=program, language=C" $ readFile (name ++ ".c") >>= putStr
    inputs <-
        zip [1..] <$> unfoldr phi <$> lines <$> readFile (name ++ ".input")
    forM_ inputs $ \(n, input) -> do
        putStrLn $ "\\subsection{実行例" ++ show n ++ "}"
        putStrLn "\\subsubsection{input}"
        latexsc "style=plain" $ putStr input
        putStrLn "\\subsubsection{output}"
        latexsc "style=plain" $ readProcess ("./" ++ name) [] input >>= putStr
    where
    phi :: [String] -> Maybe (String, [String])
    phi ls = case break (replicate 80 '-' ==) ls of
        (_, []) -> Nothing
        (l, _ : r) -> Just (unlines l, r)

