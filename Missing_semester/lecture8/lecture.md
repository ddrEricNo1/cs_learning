# Lecture 8: Metaprogramming

## Build systems

For most projects, whatever they contain code or not, there is a build process. Some sequence of operations you need to do to go from your inputs to your outputs. Often, the process might have many steps, and many branches. Run this to generate this plot, that to generate those reuslts. These are usually called "build systems". 

### make

**make** is one of the most common build systems out there. When you run **make**, it consults a file called **Makefile** in the current directory. All the targets, their dependencies, and the rules are difined in that file. 

```latex
paper.pdf: paper.tex plot-data.png
	pdflatex paper.tex
	
plot-%.png: %.dat plot.py
	./plot.py -i $*.dat -o $@
```

Each directive in this file is a rule for how to produce the left-hand side using the right-hand side. The things namd on the right-hand side are dependencies, and the left-hand side is the taret. The indented block is a sequence of programs to produce the target from those dependencies. In **make**, the first directive also defines the default goal. If you run **make** with no arguments, this is the target it will build. Alternatively, you can run somethinglike **make plot-data.png**, and it will build that target instead.

### In Makefile, % represents any string, sort of like wildcard pattern 

The **%** in a rule is a pattern, and will match the same string on the left and on the right. For example, if the target **plot-foo.png** is requested, **make** will look for the dependencies **foo.dat** and **plot.py**. 

**make** is helpfully telling us that in order to build **paper.pdf**, if needs **paper.tex**, and it has no rule telling it how to make that file. 

Whenever you execute make command, it tries to do the minimum work in order to produce what you are asking to produce.

## Dependency management

Most projectsthat other projects depend on issue a version number with every release. Usually sonething like 8.1.3 or 64.1.20192004. They are often, but not always numerical. Version numbers serve many purposes, and one of the most important of them is to ensure that software keeps working. 

With semantic versioning, every version number is of the form: major.minor.patch. The rules are:

- If a new release does not change the API, increase the patch verison.

- if you add to your API in a backwards-compatible way, increase the minor version.

- if you change the API in a non-backwards-compatible way, increase the major version. 

This provides some major advantages. Now if my project depends on your project, it should be safe to use the latest release with the same najor version as the one I built against when I dveloped it, as long as its minor verison is at least what it was back then. In other words, if I depend on your library at version **1.3.7**, then it should be fine to built in with **1.3.8**, **1.6.1**, or even **1.3.0**. Version **2.2.4** would probably not be ok, because the major version was increased. 

When working with dependency management systems, you may also come across the notion of **lock files**. A lock file is simply a file that lists the exact version you are currently depending on of each dependecy. Usually, you need to explicitly run an update program tp upgrade to newerversions of your dependencies. There are many reasons for this, such as avoiding unnecessary recompiles, having reproducible vendoring, which is where you compy all the code of your dependencies into your own project. That gives you total control over any changes to it, and lets you introduce your own changes to it, but also means you have to explicitly pull in any updates from the upstream maintainers over time.

## Continuous integration systems

As you work on larger and larger projects, you will find that there are often additional tasks you have to do whenever you make a change to it. You might have to upload a new version of the documentation, upload a compiled version somewhere, release the code to pypi, run your test suite, and all sort of other things. Maybe every time someone sends you a pull request onGitHub, you want their code to be style checked and you want some benchmarks to run? When these kinds of needs arise, it's time to take a look at continous integration.

**Continous integration**, or CI, is an imbrella term for "stuff that runs whenever your code changes", and there are many companies out there that provide various types of CI, often for free for open-source projects.Some of the big ones are Travis CI, Azure Pipelines and GitHub actions. They all work in roughly the same way: you add a file to your repository that describes whatshould happen when various things happen to that repository. By far the most common one is a rule like "When someone pushes code, run the test suite", When the event triggers, the CI provider spins up  a virtual machine, run the commands in your recipe, and then usually notes down the results somewhere. You might set it up so that you are notofied if the test suite stops passing, or so that a little badge appears on your repository as long as the test pass. 
