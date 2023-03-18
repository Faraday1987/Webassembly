#Webassembly C with Javascript

##🚀 Start
```BASH
yarn install

yarn start
```

## https://wasdk.github.io/WasmFiddle/ Editor de c

`emcc lib/demo.c -s WASM=1 -o public/demo.js`

## Export the html with wasm and js files
`emcc lib/demo.c -s WASM=1 -o public/demo.html`

## Export wasm file alone no extras
`emcc lib/demo.c -s WASM=1 -s SIDE_MODULE=1 -o public/demo.wasm`

## We can improve the compilation optimitation by 3 levels -O1 -O2 -O3
## This return very small files in kb O1 low optimitation O3 Hig Optimitation
`emcc lib/demo.c -s WASM=1 -O3 -o public/demo.js`

## Include the javascript files in compilation time at the end
`--> this will include in the demo.js output file: --post-js public/ready.js`
`emcc lib/demo.c -s WASM=1 --post-js public/ready.js -O3 -o public/demo.js`

## Include the javascript files in compilation time at start
`--> this will include in the demo.js output file: --pre-js public/ready.js`
`emcc lib/demo.c -s WASM=1 --pre-js public/ready.js -O3 -o public/demo.js`

## para exportar las funciones de C
```C
int getNumber() {
    return 22
}
```
## Debemos poner explicitamente `-s EXPORTED_FUNCTIONS="['_getNumber']"` separados por coma las funciones que serán utilizadas en javascript
`emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNumber']" --post-js public/ready.js -O3 -o public/demo.js`

## Se quita por default el main exportado, pero se agrega manualmente
`emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_main','_getNumber']" --post-js public/ready.js -O3 -o public/demo.js`

## Se pueden llamar las funciones desde js especificando nombre y tipo de retorno
`ccall('getNumber', 'number')`

## Pasando parametros
`ccall('getNumber', 'number', ['number'], [33])`


