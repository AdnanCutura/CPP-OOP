# Regex
## Rules
|Rule  |Description   |   
|---|---|
|  `[a-z]` | Range from a to z   |  
|  `[a-z0-9]`  | Range from a to z `||` 0 to 9  |  
|   |   |  

Repetitions
`*` -> none or more
`+` -> one or more
`?` -> none or one

![[Pasted image.png]]

## Functions

### Regex search

```c+
regex_search(text, rule) -> bool
```

### Regex match
```c++
regex_match(tel, regex(rule))
```