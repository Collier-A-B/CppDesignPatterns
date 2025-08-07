# Adapter Design Pattern

Primarily used as an interface or go-between for two codebases that are not compatible with eachother.
Solves the problem of integrating incompatible interfaces into existing designs

- Works by converting the interface of one class into another
- Example: integrating legacy codebase into another codebase
- Avoids complex refactoring of an entire codebase to be compatible with another

## Potential Pitfalls/Drawbacks

- Necessitates creation of new intermediary class(es)
- Increases Complexity
- Increased potential for unexpected behavior, bugs, etc.
- Increased dificulty to read/understand codebase
- Performance overhead
