$R=\{ABCDE\}$
$F=\{ABD\rightarrow C, DE\rightarrow ABC, CDE\rightarrow AB\}$

Dekomposition
$F=\{ABD\rightarrow C, DE\rightarrow A, DE\rightarrow B, DE\rightarrow C, CDE\rightarrow A, CDE\rightarrow B\}$

LR:
ABD -> C: x
DE -> A: x
DE -> C: x
CDE -> A: DE -> A wegen DE -> A
CDE -> B: DE -> B wegen DE -> B

$F=\{ABD\rightarrow C, DE\rightarrow A, DE\rightarrow B, DE\rightarrow C, DE\rightarrow A, DE\rightarrow B\}$

RR:
ABD -> C: x
DE -> A: Raus wegen DE -> A
DE -> B: Raus wegen DE -> B
DE -> C: Raus wegen DE -> A, DE -> B, ABD -> C
DE -> A: x
DE -> B: x

$F=\{ABD\rightarrow C, DE\rightarrow A, DE\rightarrow B\}$

Zusammengefasst:
$F=\{ABD\rightarrow C, DE\rightarrow AB\}$