import './App.css';
import animate from './animate';

function App() {
    return (
        < div className="App" >
            <nav class="navbar navbar-expand-lg fixed-top navbar-dark bg-dark">
                <div class="container-fluid">
                    <a class="navbar-brand" href="/"><img src="logo.png" style={{ width: 180, height: 70 }} /></a>
                    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Переключатель навигации">
                        <span class="navbar-toggler-icon"></span>
                    </button>
                    <div class="navbar navbar-nav navbar-right" id="navbarNav">
                        <form class="d-flex">
                            <canvas id="canvas"></canvas>
                            <input class="form-control me-2" type="search" placeholder="Поиск" aria-label="Поиск" />
                            <button class="btn btn-outline-success" type="submit">Поиск</button>
                        </form>
                    </div>
                </div>
            </nav >

            <main class="content-wrapper">"
                <div class="container h-100 d-flex flex-wrap justify-content-center" style={{ "padding-top": "90px", "padding-bottom": "90px" }}>
                    <div class="row row-cols-4 mb-2 mt-2 gx-5">
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="1.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 1</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="2.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 2</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="3.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 3</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="4.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 4</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="row row-cols-4 mb-2 g-5">
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="5.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 5</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="6.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 6</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="7.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 7</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                        <div class="col">
                            <div class="card " style={{ width: "18rem" }}>
                                <img src="8.png" class="card-img-top" alt="..." />
                                <div class="card-body">
                                    <h5 class="card-title">Товар 8</h5>
                                    <p class="card-text">Описание товара</p>
                                    <a href="#" class="btn btn-primary">В корзину</a>
                                </div>
                            </div>
                        </div>
                    </div>

                </div>
            </main >
            <footer id="sticky-footer" class="flex-shrink-0 py-4 bg-dark text-white-50 fixed-bottom">
                <div class="container text-center">
                    <small>Copyright &copy; Кокорев Я.С. 1045М</small>
                </div>
            </footer>
        </div >
    );
}

export default App;
