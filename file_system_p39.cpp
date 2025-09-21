reate a python class for implementing directory structure, to store the file in file system
	incorporate the file size as well and given a folder name or file name, i should be able to tell the total size of it.
	mplement delete feature

	struct Directory {
public:
		Directory(string name) {
				this->name = name;
			}
			~Directory() {
				for (auto dir : root->subDirectories) delete dir;
			}
			string name;
			int size;
			vector<string> fileNames;
			unordered_map<string, Directory*> subDirectories;
		};

/ home / test / a.txt

class FileSystem {
	Directory* root;
public:
	FileSystem() {
		root = new Directory("");
	}
	~FileSystem() {
		if (root != nullptr) {
			delete root;
		}
	}

	void insertFile(string name, int size) {
		Directory* node = root;
		for (int i = 0; i < name.size(); ) {
			node->size += size;
			int j = i + 1;
			if (s[i] != '/') j--;
			while (j < name.size() && s[j] != '/') j++;

			if (s[j] == '/') {
				string dirName = s.substr(i + 1, j - i - 1);
				if (node->subDirectories.find(dirName) == node->subDirectories.end()) {
					node->subDirectories[dirName] = new Directory("dirName");
				}
				node = node->subDirectories[dirName];
			} else {
				string fileName = s.substr(i + 1, j - i - 1);
				node->fileNames.push_back(fileName);
			}
			i = j;
		}
	}

	int findDirectorySize(string name) {
		Directory* node = root;
		for (int i = 0; i < name.size(); ) {
			int j = i + 1;
			while (j < name.size() && s[j] != '/') j++;
			string dirName = name.substr(i + 1, j - i - 1);
			if (node->subDirectories.find(dirName) == node->subDirectories.end()) {
				return 0;
			}
			node = node->subDirectories[dirName];
			i = j;
		}
		return node->size;
	}

	int deleteRecurse(Directory* node, string& name, int idx) {
		int deSz = 0;
		for (int i = idx + 1; i <= name.size(); i++) {
			if (i == name.size() || s[i] == '/') {
				string dirName = name.substr(idx + 1, i - idx - 1);
				if (!node->children.count(dirName)) return 0;
				if (i == name.size()) {
					deSz = node->children[dirName].size;
					delete node->children[dirName];
				} else {
					deSz = deleteRecurse(node->children[dirName], name, i);
					break;
				}
			}
		}
		node->size -= deSz;
		return deSz;
	}
	void deleteDirectory(string name) {
		deleteRecurse(node, name, 0);
	}
};



words = [word1, ..., word_n]

        find number of pairs (i, j) such that i < j and word_i and word_j is buddy strings



        ab, de => buddy
        ab, def => non buddy


        length => 1, any pair is a buddy string



        abc, def => buddy


        abc => zcb => non buddy

        abc => (b - a), (c - b) => 1, 1 => hash => abc => "1, 1"


        zbc => (b - z), (c - b) => 2, 1 => has Zbc =>
