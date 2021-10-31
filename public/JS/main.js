let pump =document.querySelectorAll(".pump");
pump.forEach (btn =>{
    btn.addEventListener("click",() => {
       btn.classList.toggle("active");
       if ( btn.classList.contains('active')){
        btn.innerHTML='<i class="fas fa-tint"></i>'
        }else {
            btn.innerHTML='<i class="fas fa-tint-slash"></i>'
        }
    });
    let timer =setInterval (()=> {
        window.location = window.location.href;
    },1000) ;
});