function blink()
            {
                let body = document.querySelector('body');
                if(body.style.visibility === 'hidden')
                {
                    body.style.visibility = 'visible';
                }
                else
                {
                    body.style.visibility = 'hidden';
                }
            }

            //blink every 100ms
            window.setInterval(blink, 100);