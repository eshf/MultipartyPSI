process.argv.forEach(function (val, index, array) {
  console.log(index + ': ' + val);
});

$wslIP = bash.exe -c "hostname -I"
$found = $wslIP -match '\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}';

if(! $wslIP -match '\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}') {
  echo "WSL's IP cannot be found. Aborting";
  exit;
}

export PS2=$(node /home/itsnorie/MultipartyPSI/index.js)