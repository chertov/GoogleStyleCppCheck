
// Copyright (c) 2009 Chertov Maxim <chertovm@gmail.com>

#define DEF_MAX(i, j) ((i) > (j) ? (i) : (j)) // хорошо

// #define MAX(i, j) ((i) > (j) ? (i) : (j)) // плохо


#ifdef
#ifdef
#define
#define

#ifdef __cplusplus
extern "C"
{
#endif
namespace
{
namespace TestExample
{
namespace SourceCode
{
/// doxygen comment
struct Sstr
{
    int k;
}

class CBaseObject   // NOLINT(comment/doxygen)
{
public:
    std::vector<int> array;  // NOLINT(build/include_what_you_use)
}

/// A class of arrays
template <class T>
class CArray : public CBaseObject
{
}

    template <class T>
    class CArray1 : public CBaseObject   // NOLINT(comment/doxygen)
    {
    }

{
    /// asasdasd
    class test // NOLINT(build/class)
    {
    public:
    private:
    protected:


    private slots:
    signals:



        int t;
        if(t == 1)  // NOLINT(whitespace/parens)
            std::cout << "Hello, World!" << std::endl;
        else
        {
            std::cout << t << std::endl;

            int l;
#ifdef _WIN64 // NOLINT(whitespace/preprocessor_directive)
            if(l == 1)int k;      // NOLINT(whitespace/parens)
#endif // _WIN64
        }

        if (m == 1)
        {
            int l; // test
        }
    }

    int t;
    int t;
    int p;
}

void main(int i, int j)
{
    if (i == j)
        int pk;
    else if (i != j)
    {
    }
}

void main(int i, int j)
{
    if (i == j)
    {
        {
            while (true)
            {
                int p;
            }
        }
    }
    else if (i != j)
    {
      int ds; // NOLINT
    }
    else
    {
    }
}

void ClassName::Method() {    // NOLINT
    switch (var)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            break;
        }
        default:
        {
            assert(false);
        }
    }
}
}
}
}
#ifdef __cplusplus
}
#endif
