# NPSI
Docker Compose Driver for osu-crypto (MultipartyPSI)

Referenced from https://github.com/osu-crypto/MultipartyPSI/tree/implement

Programmable Oblivious PRF & multi-party PSI This is the implementation of our CCS 2017 paper: Practical Multi-party Private Set Intersection from Symmetric-Key Techniques[ePrint].

Evaluating on a single Intel Xeon server (2 36-cores Intel Xeon CPU E5-2699 v3 @ 2.30GHz and 256GB of RAM), ours protocol requires only 71 seconds to securely compute the intersection of 5 parties, each has 2^20-size sets, regardless of the bit length of the items.

For programmable OPRF, this code implements:

Table-based OPPRF Polynomial-based OPPRF BloomFilter-based OPPRF For PSI, we implement multi-party PSI (nPSI) in augmented-semihonest model and standard semihonest model.

Installations Required libraries C++ compiler with C++14 support. There are several library dependencies including Boost, Miracl, NTL , and libOTe.

Latest Boost version is added to the repository.

Libraries Needed:

Install Boost Can be obtained from: https://www.boost.org/users/download/ Asio folder can be clone from https://github.com/boostorg/asio

Miracl Windows: open PowerShell, cd ./thirdparty, and .\all_win.ps1 (the script works with Visual Studio 2015. For other version, you should modify MSBuild at several places in the script.) Linux:

a. cd ./thirdparty/linuxmiracl/miracl/source bash linux64 

b. cd ./thirdparty/linux/miracl/miracl_osmt/source bash linux64_cpp

NTL Linux: cd ./thirdparty/linux bash ntl.get
For libOTe, it requires CPU supporting PCLMUL, AES-NI, and SSE4.1. Optional: nasm for improved SHA1 performance. Our code has been tested on both Windows (Microsoft Visual Studio) and Linux. To install the required libraries:

Install Docker: https://www.docker.com/

A. Make sure Windows Features is turned on, to use Linux Distribution on Windows:

Start>Search>Turn on/off Windows Features a. Virtual Machine Platform option is checked b. Windows Subsystem for Linux is checked (Install app on Microsoft Store)

To install WSL2 on Windows: Launch Powershell as Adminstrator, type wsl --install -d Ubuntu (for Ubuntu distro)

Recommended IDEs: VS Code

To open project on WSL2 using VS Code IDEs

Launch Ubuntu as Administrator (After Ubuntu distro is installed, above step)
Make sure project is copied to Linux directory on your local disk first

cd to project directory, code .

For opening projects stored in C drive and other directories (Windows)

Navigate to mnt/c (for instance)

B. For IDEs: VS Code is recommended, follow this guide to install WSL2 on Windows: https://code.visualstudio.com/blogs/2019/09/03/wsl2
