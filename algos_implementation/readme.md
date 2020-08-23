### Implementations of some algorithms

#### Union Find: Benchmarks

**10<sup>5</sup> union operations**

- Basic Union Find:  **0.0661671978600134**
- Size Weighted Union, Basic Find:  **0.06496675934999076**
- Basic Union, Path compression in find:  **0.11662584623998555**
- Size Weighted Union,, Path compression in find:  **0.12000587567999901**

Results are not what was expected. Is the path compression implementation wrong? (Two traversals)

Todo: Grandchildren approach!