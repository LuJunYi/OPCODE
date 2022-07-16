# OPCODE 

## Github仓库

https://github.com/LuJunYi/OPCODE.git

## 官方网站

http://www.codercorner.com/Opcode.htm

可以获取历史版本代码、测试框架代码、Demo程序、说明帮住文档等；

## 存在问题

*源码仅支持win32，目前Turbowork使用的代码已经修改支持x64；*



Optimized Collision Detection

*OPCODE* is a new small collision detection library. It is similar to popular packages such as [SOLID](http://www.win.tue.nl/~gino/solid/index.html) or [RAPID](http://www.cs.unc.edu/~geom/OBB/OBBT.html), but more memory-friendly, and often faster.

### FEATURES

\-     C++ interface, developed for Windows systems using VC++ 6.0

\-     Works on arbitrary meshes (convex or non-convex), even polygon soups

\-     Current implementation uses AABB-trees

\-     Introduces Primitive-BV overlap tests during recursive collision queries (whereas standard libraries only rely on Primitive-Primitive and BV-BV tests)

\-     Introduces no-leaf trees, i.e. collision trees whose leaf nodes have been removed

\-     Supports collision queries on quantized trees (decompressed on-the-fly)

\-     Supports "first contact" or "all contacts" modes (à la RAPID)

\-     Uses temporal coherence for "first contact" mode (~10 to 20 times faster, useful in rigid body simulation during bisection)

\-     Memory footprint is 7.2 times *smaller* than RAPID's one, which is ideal for console games with limited ram (actually, if you use the unmodified RAPID code using double precision, it's more like *13 times* smaller...)

\-     And yet it often runs *faster* than RAPID (according to RDTSC, sometimes more than 5 times faster when objects are deeply overlapping)

\-     Performance is usually close to RAPID's one in close-proximity situations

\-     Stabbing, planes & volume queries (sphere, AABB, OBB, LSS)

\-     Sweep-and-prune and radix-based box pruner

\-     Now works with deformable meshes (OPCODE 1.3)

\-     Hybrid trees (OPCODE 1.3) keep a maximum of 16 triangles per leaf and reorganize client triangle lists, to eventually need roughly 16 times less ram than OPCODE’s standard trees. In the best case, this goes down to 1.25 byte / triangle, which is *115 times smaller* than RAPID’s OBB trees (using floats ! else it’s *168* times). Speed hit is often negligible, and volume queries can actually run faster than OPCODE 1.2 due to less cache misses (reorganizing clients arrays also helps in this regard). They’re also faster for deformable meshes.

### DOWNLOAD

Version 1.3

[Download OPCODE 1.3](http://www.codercorner.com/Opcode.zip)

[Opcode 1.3 Test Framework](http://www.codercorner.com/CDTestFramework.rar)

Version 1.2

[Download OPCODE 1.2](http://www.codercorner.com/Opcode12.zip)

Version 1.2 has also been ported to [Linux](http://www.paassen.tmfweb.nl/) by W.P. van Paassen. He also included an Opcode demo in [The Demo Effects Collection](http://demo-effects.sourceforge.net/).

Version 1.1

[Download OPCODE 1.1](http://www.codercorner.com/Opcode11.zip)

Version 1.0

[Download OPCODE 1.0](http://www.codercorner.com/Opcode10.zip)

You’re free to use them in any commercial or non-commercial program.

### DEMO 

A demo is available to compare OPCODE 1.0 and RAPID (requires Windows / DirectX7) :

[Download OPCODE Demo](http://www.codercorner.com/OpcodeDemo.zip)

It has been tested on GeForce 1&2, ATI RAGE 128 and INTEL i740 cards. If it doesn’t run on your system (I can’t test all OS / Card / Driver configurations), here’s a [summary of the demo](http://www.codercorner.com/OpcodeDemo.htm). 

*Note that Opcode 1.3 is faster than version 1.0 !*

### USERS

A little (incomplete) list of projects using OPCODE has been added [here](http://www.codercorner.com/OpcodeUsers.htm).

### RELATED READING

White paper (for version 1.0 !):

[Opcode.pdf](http://www.codercorner.com/Opcode.pdf)

User manual (for version 1.2 !):

[OpcodeUserManual.pdf](http://www.codercorner.com/OpcodeUserManual.pdf)

Questions ? Suggestions ? Comments ?

Drop me a [mail.](mailto:p.terdiman@codercorner.com?subject=OPCODE)

-Last updated : June 5, 2003 - Pierre Terdiman

[Back to main](http://codercorner.com/Pierre.htm)

 
