## RegEx Makeover

1. Match 24-hour times of the format HH: MM

```markdown
((2[0-3])|([0-1]\d)):[0-5]\d
```

2. Match any tweet talking about GME stock.

```markdown
\bGME\b
\b stands for word bondary: matches a boundary position between a word character and non-word character or position(start/end of string)
```

