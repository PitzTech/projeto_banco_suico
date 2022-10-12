# Projeto Banco Pelado

![Scheme](https://global.discourse-cdn.com/nubank/original/4X/d/6/e/d6e8868a885866c84bb2489d1cfcd675fdd08c60.gif)

## Como executar

`./start.sh`

## Como limpar

`./clean.sh`

## Comandos Úteis

**Para adicionar permissão de execução à um arquivo:** \
`chmod +x the_file_name`

**Para compilar manualmente digite:** \
`make all`

**Para limpar manualmente digite:** \
`make clean`

**Para corrigir erro de "missing separator" digite:** \
`vim makefile` 

E dentro do vim insira: &nbsp;&nbsp;`:%s/^[ ]\+/\t/g` 

E `:wq` para salvar e sair (write , quit)

## Referências
[1] [Emcarcados](https://embarcados.com.br/introducao-ao-makefile/) 
