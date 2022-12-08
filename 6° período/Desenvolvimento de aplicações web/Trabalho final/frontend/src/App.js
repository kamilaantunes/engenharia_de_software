import '../node_modules/bootstrap/dist/css/bootstrap.css';

import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';

import Header from './components/Header';
import Produtos from './pages/Produtos';
import Sobre from './pages/Sobre';
import Login from './pages/Login';

function App() {
  return (
    <Router>
      <div>
        <Header />
        
        <div className='container'>
          <Routes>
            <Route path='/' element={<Produtos />} />
            <Route path='/sobre' element={<Sobre />} />
            <Route path='login' element={<Login />} />
          </Routes>
        </div>
      </div>
    </Router>
  );
}

export default App;
