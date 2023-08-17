# lecture 6: Version control (Git)

Version control systems are tools used to keep track changes to source code (or other collections of files and folders). As the name implies, these tools help maintain a history of changes; furthermore, they facilitate collaboration. VCSs track changes to a folder and its contents in a series of snapshots, where each snapshot encapsulates the entire state of files/folders within a top-level directory. VSCs also maintain metadata like who created each snapshot, messages associated with each snapshot, and so on.

1. **Git's data model**

   **snapshots**

   Git models the history of a collection of files and folders within some top-level directory as a series of snapshots. In Git terminology, a file is called a "blob", and it's just a bunch of bytes. A directory is called a "tree", an it maps names to blobs or trees(so directories can contain other directories). A snapshot is the top-level tree that is being tracked. 

2. **Modeling history: relating snapshots**

   How should a version control system relate snapshots? One simple model would be to have a linear history. A history would be a list of snapshots in time-order. For many reasion, git doesn't use a simple model like this. 

   In Git, a history is a directed acyclic graph(DAG) of snapshots. All this means that each snapshot in Git refers to a set of parents, the snapshots that preceded it. It's a set of parents rather than a single parent(as would be the case in linear history) because a snapshot might descend from multiple parents, for example, due to combining two parallel branches of development.

3. **Data model and pseudocode**

   It may be instructive to see Git's data model written down in pseudocode:

   ```markdown
   // a file is bunch of bytes
   type blob = array<byte>
   
   // a directory contains named files and directories
   type tree = map<string, tree | blob>
   
   // a commit has parents, metadata, and the top-level tree
   type commit = struct {
   	parent: array<commit>
   	author: string
   	message: string
   	snapshot: tree
   }
   ```

4. **Objects and content-addressing (对象和内存寻址)**

   An object is a blob, tree or commit

   ```markdown
   type object = blob | tree | commit
   ```

   In Git data store, all objects are content-addressed by their SHA-1 hash.

   ```markdown
   objects = map<string, object>
   
   def store(object):
   	id = sha1(object)
   	objects[id] = object
   
   
   def load(id):
   	return objects[id]
   ```

   Blobs, trees and commits are unified in this way: they are all objects. When they reference other objects,  they don't acutally contain them in their on-disk representation, but have a reference to them by their hash.

5. **References**

   All snapshots can be identified by their SHA-1 hashes. 

   Git's solution to this problem is human-readable names ofr SHA-1 hashes, called "references". References are pointers to commits. Unlike objects, which are immutable, references are mutable (can be updated to point to a new commit). For example, the master reference usually points to the latest commit in the main brach of development.

   ```markdown
   references = map<string, string>
   
   def update_reference(name, id):
   	references[name] = id
   
   def read_references(name):
   	return references[name]
   	
   def load_reference(name_or_id):
   	if name_or_id in references:
   		return load(references[name_or_id])
   	else:
   		return load(name_or_id)
   ```

   With this, Git can use human-readable names like "master" to refer to a particular snapshot in this history, instead of a long hexadecimal string. 

   One detail is that we often want a notion of "where we currently are" in the history, so that when we take a new snapshot, we know what it is relative to (how we set the parents field of the commit). In Git, that "where we currently are" is a special reference called "HEAD". 

6. **Repositories**

   What is a Git repository: it is the data objects and references. 

   On disk, all Git stores are objects and references: that's all there is to Git's data model. All git commands map to some manipulation of the commit DAG by adding objects and adding/updating references. 

7. **Staging area**

   This is another concept that's orthogonal to the data model, but it's a part of the interface to create commits. Imagine a scenario where you've implemented two separate features, and you want to create two separate commits, where the first introduces the first feature, and the next introduces the second feature. Or image a scenario where you have debugging print statements added all over the code, along with a bugfix, you want to commit the bugfix while discarding all the print staatements.

   **Staging area** allows you to specify which modifications should be included in the next snapshot.

8. **Git command-line interface**

   **Basics**

   * git help <command>: get help for a git command
   * git init: create a new git repo, with data stored in the .git directory
   * git status: tells you what's going on
   * git add <filename>: add files to staging area
   * git commit: creates a new commit
   * Git log: show a flattened log of history
   * git log --all --graph --decorate: visualizes history as a DAG
   * git diff <filename>: show changes you made relative to the staging area
   * git diff <version> <filename>: show differences in a file between snapshots

   **Branching and merging**

   * git branch: show branches
   * git branch <name>: create a branch
   * git checkout -b <name>: create a branch and swithes to it
   * git merge <revision>: merges into current branch
   * git mergetool: use a fancy tool to help resolve merge conflicts
   * git rebase: rebase set of patches onto a new base

   **Remotes**

   * git remote: list remotes
   * git remore add <name> <url>: add aremote
   * git push <remote> <local branch>: <remote branch>: send objects to remote, and update remote reference