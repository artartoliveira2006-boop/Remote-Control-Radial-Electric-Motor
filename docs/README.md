# Documentação

O relatório acadêmico foi revisado com base no documento original da equipe e na organização adotada no relatório do projeto da garra articulada.

Arquivos disponíveis:

- [`relatorio/Motor_Radial_Relatorio_Revisado.tex`](relatorio/Motor_Radial_Relatorio_Revisado.tex): fonte editável em LaTeX;
- [`../output/pdf/Motor_Radial_Relatorio_Revisado.pdf`](../output/pdf/Motor_Radial_Relatorio_Revisado.pdf): versão compilada e revisada.

A revisão acrescenta elementos pré-textuais, imagens do projeto, referências visuais licenciadas, tabelas de pinagem e fabricação, metodologia, verificações, segurança e propostas de evolução. Afirmações sobre eficiência, torque, RPM e desempenho térmico foram limitadas ao que pode ser sustentado pelas evidências disponíveis.

Para recompilar a partir da raiz do repositório:

```bash
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=output/pdf docs/relatorio/Motor_Radial_Relatorio_Revisado.tex
pdflatex -interaction=nonstopmode -halt-on-error -output-directory=output/pdf docs/relatorio/Motor_Radial_Relatorio_Revisado.tex
```
