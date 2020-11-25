# Sort the columns of CSV data

## Instructions

You get a string with content in the CSV format.
The columns are separated by semicolons.
The first line contains the names of the columns.
Write a method that sorts the columns by the names of the columns alphabetically and in case sensitive.
An example:

### Before sorting

Table
---

|myjinxin2015|raulbc777|smile67|Dentzil|SteffenVogel_79|
|:----------:|:-------:|:-----:|:-----:|:-------------:|
|17945|10091|10088|3907|10132|
|2|12|13|48|11|

CSV
---
```
myjinxin2015;raulbc777;smile67;Dentzil;SteffenVogel_79\n
17945;10091;10088;3907;10132\n
2;12;13;48;11
```

### After sorting

Table
---

|Dentzil|myjinxin2015|raulbc777|smile67|SteffenVogel_79|
|:-----:|:----------:|:-------:|:-----:|:-------------:|
|3907|17945|10091|10088|10132|
|48|2|12|13|11

CSV
---

```
Dentzil;myjinxin2015;raulbc777;smile67;SteffenVogel_79\n
3907;17945;10091;10088;10132\n
48;2;12;13;11
```

There is no need for prechecks. You will always get a correct string with more than 1 line and more than 1 row. All columns will have different names.