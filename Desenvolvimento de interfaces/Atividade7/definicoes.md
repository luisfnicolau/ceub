HTML é uma linguagem de marcação sendo usada como o bloco de construção mais basico da web. Ele define o significado e a estrutura do conteúdo na web.
HTML significa Linguagem de Marcacão em Hypertexto, onde hypertexto refere-se a links que conectam pagina s da web entre si, seja dentro de um único site ou entre sites.
O termo Marcaçcão se refere à anotar texto, imagem e outros conteúdos para exibição em um navegador da Web, para isso, a maracação HTML inclui elementos especiais, conhecidos como "tags",
como <head>, <title>, <body>, <header>, <footer>, <article>, <section>, <p>, <div>, <span>, <img>, <aside>, <audio>, <canvas>, <datalist>, <details>, <embed>, <nav>, <output>, <progress>, <video>, <ul>, <ol>, <li> e muitos outro.
O HTML foi criado em 1991 pro Tim Berners-Lee, no CERN, com o objetivo de interligar intituições de pesquisa próximas e compartilahr documentos com facilidade, e isso proporcionou um método para, em conjunto com o lançamento da World Wide Web, criar uma rede de compartilhamento de alcance mundial.

1. **Principais tags HTML e utilidades (resumo)**
- `<!doctype html>`: indica ao navegador que o documento é HTML5.
- `<html>`: elemento raiz do documento.
- `<head>`: contém metadados (não aparece no conteúdo da página).
- `<meta>`: define metadados (ex.: charset, viewport, descrição).
- `<title>`: título da aba/janela do navegador.
- `<link>`: liga arquivos externos (ex.: CSS, ícones).
- `<script>`: adiciona/ referencia JavaScript.
- `<body>`: tudo que aparece visualmente na página fica aqui.

**Estrutura/semântica (organização do conteúdo):**

- `<header>`: cabeçalho da página ou de uma seção (logo, título, menu).
- `<nav>`: área de navegação (menu de links).
- `<main>`: conteúdo principal (deve ser único por página).
- `<section>`: seção temática do conteúdo.
- `<article>`: conteúdo independente (post, notícia, card que faz sentido sozinho).
- `<aside>`: conteúdo complementar (barra lateral, relacionados).
- `<footer>`: rodapé da página ou de uma seção.

**Texto e formatação (conteúdo):**

- `<h1>` a `<h6>`: títulos e subtítulos por níveis (hierarquia).
- `<p>`: parágrafo.
- ``: quebra de linha (use com moderação).
- `<strong>`: importância forte (geralmente negrito).
- `<em>`: ênfase (geralmente itálico).
- `<span>`: contêiner inline para aplicar estilos/identificação em pequenos trechos.

**Links, listas e mídia:**

- `<a>`: link (interno/externo).
- `<ul>`: lista não ordenada.
- `<ol>`: lista ordenada.
- `<li>`: item de lista.
- `<img>`: imagem (requer `alt` para acessibilidade).
- `<video>` / `<audio>`: mídia.
- `<source>`: arquivos/fontes alternativas para `<video>`/`<audio>`.
- `<figure>` e `<figcaption>`: agrupa mídia e legenda.

**Formulários (entrada de dados):**

- `<form>`: formulário.
- `<label>`: rótulo de campo (associa com `for`).
- `<input>`: campo de entrada (texto, email, senha, etc.).
- `<textarea>`: campo de texto longo.
- `<select>` e `<option>`: lista de seleção.
- `<button>`: botão de ação.

**Tabelas (dados tabulares):**

- `<table>`: tabela.
- `<tr>`: linha.
- `<th>`: célula de cabeçalho.
- `<td>`: célula de dado.

---

1. **Tabela: boas práticas vs más práticas em HTML**

| Boas práticas | Más práticas |  |
| --- | --- | --- |
| Usar **tags semânticas** (`<main>`, `<header>`, `<nav>`, `<section>`, `<article>`, `<footer>`) | Usar `<div>` para tudo, sem significado semântico |  |
| Manter **hierarquia correta de títulos** (um `<h1>` principal e subtítulos coerentes) | Pular níveis (ex.: `<h1>` → `<h4>`) só por “tamanho” |  |
| Colocar `lang="pt-BR"` (ou idioma correto) em `<html>` | Omitir o idioma da página (piora acessibilidade e SEO) |  |
| Definir `<meta charset="utf-8">` e `<meta name="viewport" content="width=device-width, initial-scale=1">` | Esquecer charset/viewport e ter problemas de acentuação e responsividade |  |
| Usar `alt` descritivo em imagens (`<img alt="...">`) | Usar `alt=""` sem motivo, ou não usar `alt` (inacessível) |  |
| Usar `<label>` associado a campos (`for="id"`), e tipos corretos (`type="email"`) | Campos sem rótulo, usando só placeholder (ruim para acessibilidade) |  |
| Validar o HTML e manter **indentação/organização** consistente | HTML “bagunçado”, difícil de manter e com tags mal fechadas |  |
| Separar responsabilidades: **HTML (estrutura)**, **CSS (estilo)**, **JS (comportamento)** | Colocar muito estilo inline (`style="..."`) e misturar tudo |  |
| Usar links com texto claro (“Ver detalhes do curso”) | Links genéricos (“clique aqui”) sem contexto |  |
| Usar tabela **apenas para dados** e com `<th>` quando houver cabeçalho | Usar `<table>` para layout da página (prática antiga e ruim) |  |
| Garantir que botões sejam `<button>` (ações) e links sejam `<a>` (navegação) | Usar `<div>` clicável para tudo (piora acessibilidade/teclado) |  |
| Carregar scripts de forma adequada (`defer`/final do body quando fizer sentido) | Scripts bloqueando renderização sem necessidade |  |

Fontes:
https://developer.mozilla.org/pt-BR/docs/Web/HTML
https://www.infoescola.com/informatica/html/

https://www.w3schools.com/html/default.asp   
https://developer.mozilla.org/pt-BR/docs/Web/HTML/Reference/Elements