#ifndef FILE_H
#define FILE_H

template <typename fileType>
class File {
    fileType associatedStruct;

    public:
        File(std::string& name, std::string& path, fileType associatedStruct);
};

#endif /* FILE_H */