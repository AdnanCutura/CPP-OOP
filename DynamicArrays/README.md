# Dinamički nizovi 

## Dodavanje automobila

```c++
&bmw	0x00affb34 {_naziv="BMW M3" _snagakW=0x00c5dfb8 {150} }	Auto *
&golf	0x00affb0c {_naziv="Golf" _snagakW=0x00c58248 {70} }	Auto *
&megane	0x00affb5c {_naziv="Megane" _snagakW=0x00c5df88 {70} }	Auto *

kramar	{_naziv="Kramar" _maxKapacitet=10 _automobili=0x00000000 <NULL> ...}	Salon
```


### Dodaj Automobil I ulaz 
```c++
&automobil	0x00aff9d0 {0x00affb5c {_naziv="Megane" _snagakW=0x00c5df88 {70} }}	Auto * 

&temp	0x00aff9a8 {0x00c5c7bc {_naziv="Megane" _snagakW=0x00c58278 {70} }}	Auto * * // operator dodjele kopija automobila

&_automobili	0x00affafc {0x00c5c7bc {_naziv="Megane" _snagakW=0x00c58278 {70} }}	Auto * *
```

### Dodaj Automobil II ulaz

```c++
&automobil	0x00aff9d0 {0x00affb34 {_naziv="BMW M3" _snagakW=0x00c5dfb8 {150} }}	Auto * *

&temp	0x00aff9a8 0x00c57ab4 {_naziv="Megane" _snagakW=0x00c579a0 {70} }	Auto * *
&temp[0]	0x00c57ab4 {_naziv="Megane" _snagakW=0x00c579a0 {70} }	Auto *	
&temp[1]	0x00c57ad4 {_naziv="BMW M3" _snagakW=0x00c579d0 {150} }	Auto *

&_automobili	0x00affafc 0x00c57ab4 {_naziv="Megane" _snagakW=0x00c579a0 {70} }	Auto * *
&_automobili[0]	0x00c57ab4 {_naziv="Megane" _snagakW=0x00c579a0 {70} }	Auto *
&_automobili[1]	0x00c57ad4 {_naziv="BMW M3" _snagakW=0x00c579d0 {150} }	Auto *
```

### Dodaj Automobil III ulaz

```c++
&automobil	0x00aff9d0 {0x00affb0c {_naziv="Golf" _snagakW=0x00c58248 {70} }}	Auto * *

&temp	0x00aff9a8 {0x00c5f36c {_naziv="Megane" _snagakW=0x00c63a78 {70} }}	Auto * *
&temp[0]	0x00c5f36c {_naziv="Megane" _snagakW=0x00c63a78 {70} }	Auto *
&temp[1]	0x00c5f38c {_naziv="BMW M3" _snagakW=0x00c63838 {150} }	Auto *
&temp[2]	0x00c5f3ac {_naziv="Golf" _snagakW=0x00c63ad8 {70} }	Auto *

&_automobili	0x00affafc {0x00c5f36c {_naziv="Megane" _snagakW=0x00c63a78 {70} }}	Auto * *
&_automobili[0]	0x00c5f36c {_naziv="Megane" _snagakW=0x00c63a78 {70} }	Auto *
&_automobili[1]	0x00c5f38c {_naziv="BMW M3" _snagakW=0x00c63838 {150} }	Auto *
&_automobili[2]	0x00c5f3ac {_naziv="Golf" _snagakW=0x00c63ad8 {70} }	Auto *
```

## Dodavanje radnika
```c++
&adnan	0x0076f7a4 {_rating=0x00be7be0 {4} _ime="Adnan" }	Radnik *
&edin	0x0076f77c {_rating=0x00be7c10 {5} _ime="Edin" }	Radnik *
&haris	0x0076f754 {_rating=0x00be78d8 {3} _ime="Haris" }	Radnik *
```
### Dodaj radnika I ulaz

```c++
&radnik	0x0076f5b0 {0x0076f7a4 {_rating=0x00be7be0 {4} _ime="Adnan" }}	Radnik * *

_radnici	0x0076f714 {0x00bec2a0 {_rating=0x00bf35c0 {4} _ime="Adnan" }, 0x00000000 <NULL>, 0x00000000 <NULL>}	Radnik *[3]
    
_radnici[0]	0x00bec2a0 {_rating=0x00bf35c0 {4} _ime="Adnan" }	Radnik *
```

### Dodaj radnika II ulaz

```c++
&radnik	0x0076f5b0 {0x0076f77c {_rating=0x00be7c10 {5} _ime="Edin" }}	Radnik * *

_radnici	0x0076f714 {0x00bec2a0 {_rating=0x00bf35c0 {4} _ime="Adnan" }, 0x00bec750 {_rating=0x00bf3590 {...} ...}, ...}	Radnik *[3]
    
_radnici[0]	0x00bec2a0 {_rating=0x00bf35c0 {4} _ime="Adnan" }	Radnik *
_radnici[1]	0x00bec750 {_rating=0x00bf3590 {5} _ime="Edin" }	Radnik *
```

### Dodaj radnika III ulaz

```c++
&radnik	0x0076f5b0 {0x0076f754 {_rating=0x00be78d8 {3} _ime="Haris" }}	Radnik * *

_radnici	0x0076f714 {0x00bec2a0 {_rating=0x00bf35c0 {4} _ime="Adnan" }, 0x00bec750 {_rating=0x00bf3590 {...} ...}, ...}	Radnik *[3]
_radnici[0]	0x00bec2a0 {_rating=0x00bf35c0 {4} _ime="Adnan" }	Radnik *
_radnici[1]	0x00bec750 {_rating=0x00bf3590 {5} _ime="Edin" }	Radnik *
_radnici[2]	0x00bec610 {_rating=0x00bf3620 {3} _ime="Haris" }	Radnik *
```

