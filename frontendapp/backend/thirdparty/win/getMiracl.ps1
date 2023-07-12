<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> a5fd074d (commit 12.7.2023)
﻿
# Update this if needed
$MSBuild = 'C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe'
#$cl = 'C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\cl.exe'
$git = 'git'



if(!(Test-Path $MSBuild))
{
    Write-Host "Could not find MSBuild as"
    Write-Host "     $MSBuild"
    Write-Host ""
    Write-Host "Please update its lication in the script"

    exit
}
 
$startDir = $PWD
 
$folder =  "$PWD\miracl"

cd $folder

& $MSBuild miracl.sln  /p:Configuration=Release /p:Platform=x64
& $MSBuild miracl.sln  /p:Configuration=Debug /p:Platform=x64

cd $startDir
<<<<<<< HEAD
=======
﻿
# Update this if needed
$MSBuild = 'C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe'
#$cl = 'C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\cl.exe'
$git = 'git'



if(!(Test-Path $MSBuild))
{
    Write-Host "Could not find MSBuild as"
    Write-Host "     $MSBuild"
    Write-Host ""
    Write-Host "Please update its lication in the script"

    exit
}
 
$startDir = $PWD
 
$folder =  "$PWD\miracl"

cd $folder

& $MSBuild miracl.sln  /p:Configuration=Release /p:Platform=x64
& $MSBuild miracl.sln  /p:Configuration=Debug /p:Platform=x64

cd $startDir
>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
=======
>>>>>>> a5fd074d (commit 12.7.2023)
